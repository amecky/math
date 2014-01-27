#pragma once

inline float catmullRom(float t, float v0, float v1, float v2, float v3) {
	const float tt = t*t;
	return 0.5f*((2.0f*v1)+(-v0+v2)*t+(2.0f*v0-5.0f*v1+4.0f*v2-v3)*tt+(-v0+3.0f*(v1-v2)+v3)*tt*t);
}

enum PathInterpolation {
	PI_LINEAR,
	PI_STEP,
	PI_CUBIC
};

enum PathLoopMode {
	PLM_ZERO,
	PLM_LAST,
	PLM_LOOP
};

template<class T>
struct PathItem {

	float time;
	T value;
};

template<int Size,class T>
class IPath {

public:
	IPath();
	~IPath() {}

	void add(float timeStep,const T& value);
	//! Gets the value at the given time
	/*
		\param time the normalized time
		\param ret a pointer to the value
		\return true if value was set
	*/
	bool get(float time,T* ret);
	//! Reset the internal list
	void reset() {
		m_Count = 0;
	}
	//! Returns the number of elements
	/*
	 * \return number of elements
	*/
	int size() {
		return m_Count;
	}
	//! Returns the timestep value at the given index
	/*
	 * \return timestep at index
	*/
	const float key(int index) const {
		return m_Array[index].time;
	}
	//! Returns value at the given index
	/*
	 * \return value at index
	*/
	const float value(int index) const {
		return m_Array[index].value;
	}
	//! Sets interpolation mode
	void setInterpolationMode(const PathInterpolation& interpolation) {
		m_Interpolation = interpolation;
	}
	//! Sets the loop mode
	/*!
	 * The loop mode defines the behavior if the timestep used in
	 * the get call exceeds the last timestep in the last. It will
	 * either be set to max or zero or subtract the max from current
	 *
	 * \param loopMode the actual LoopMode that should be used
	*/
	void setLoopMode(const PathLoopMode& loopMode) {
		m_LoopMode = loopMode;
	}
private:	
	PathItem<T> m_Array[Size];
	PathLoopMode m_LoopMode;
	PathInterpolation m_Interpolation;
	int m_Count;
};

template<int Size,class T>
IPath<Size,T>::IPath() : m_Count(0) , m_LoopMode(PLM_LAST) , m_Interpolation(PI_LINEAR) { }

template<int Size,class T>
void IPath<Size,T>::add(float timeStep,const T& value) {
	if ( m_Count < Size ) {
		// FIXME: make sure timestep is 0.0 to 1.0
		PathItem<T>* item = &m_Array[m_Count];
		item->time = timeStep;
		item->value = value;
		++m_Count;
	}
}

template<int Size,class T>
bool IPath<Size,T>::get(float time,T* ret) {
	if ( m_Count == 0 ) {
		return false;
	}
	if ( m_Count == 1 ) {
		*ret = m_Array[0].value;
		return true;
	}
	float normTime = time;
	if ( m_LoopMode == PLM_ZERO ) {
		float maxTime = m_Array[m_Count-1].time;
		if ( normTime > maxTime ) {
			normTime = 0.0f;
		}
	}
	else if ( m_LoopMode == PLM_LAST ) {
		float maxTime = m_Array[m_Count-1].time;
		if ( normTime > maxTime ) {
			normTime = maxTime;
		}
	}
	else if ( m_LoopMode == PLM_LOOP ) {
		float minTime = m_Array[0].time;
		float maxTime = m_Array[m_Count-1].time;       
		normTime = fmod(time,(maxTime-minTime));
	}
	for ( int i = 0; i < m_Count - 1 ; ++i ) {
		PathItem<T>* current = &m_Array[i];
		PathItem<T>* next = &m_Array[i+1];
		if ( normTime >= current->time && normTime <= next->time ) {
			float t = ( normTime - current->time ) / ( next->time - current->time);
			if ( m_Interpolation == PI_LINEAR) {
				*ret = current->value + ( next->value - current->value) * t;
				return true;
			}
			else if ( m_Interpolation == PI_STEP) {
				if ( normTime == 1.0f ) {
					*ret = next->value;
					return true;
				}
				*ret = current->value;
				return true;
			}

			else if ( m_Interpolation == PI_CUBIC ) {
				T prev = current->value;
				if ( i > 0 ) {
					prev = m_Array[i-1].value;
				}
				T nextNext = next->value;
				if ( i < m_Count -2 ) {
					nextNext = m_Array[i+2].value;
				}
				*ret = catmullRom(normTime,prev,current->value,next->value,nextNext);
				return true;
			}
		}
	}
	return false;
}



