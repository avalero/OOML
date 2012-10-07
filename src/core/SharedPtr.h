/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño
 *
 * OOML is licenced under the Common Creative License,
 * Attribution-ShareAlike 3.0
 *
 * You are free:
 *   - to Share - to copy, distribute and transmit the work
 *   - to Remix - to adapt the work
 *
 * Under the following conditions:
 *   - Attribution. You must attribute the work in the manner specified
 *     by the author or licensor (but not in any way that suggests that
 *     they endorse you or your use of the work).
 *   - Share Alike. If you alter, transform, or build upon this work,
 *     you may distribute the resulting work only under the same or
 *     similar license to this one.
 *
 * Any of the above conditions can be waived if you get permission
 * from the copyright holder.  Nothing in this license impairs or
 * restricts the author's moral rights.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 **********************************************************************/

#ifndef SHAREDPTR_H_INCLUDED
#define SHAREDPTR_H_INCLUDED

#include <utility>

/**
 * \brief Object pointer.
 *
 * This class provides a shared_ptr like interface to deal with
 * multiple references of objects.
 */
template <typename T>
class SharedPtr
{
public:
  /** Element hold by the shared pointer */
	typedef T element_type;

	/**
	 * \brief Default constructor.
	 */
	SharedPtr() :
		_ptr(0),
		_counter(0)
	{}
	/**
	 * \brief Basic constructor.
	 *
	 * The passed ptr belongs to the shared pointer.
	 *
	 * \param ptr Object to be hold by the shared pointer.
	 */
	SharedPtr(T * ptr) :
		_ptr(ptr),
		_counter(new int(1))
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other pointer to copy from.
	 */
	SharedPtr(SharedPtr<T> const& other)
	{
		_ptr = other.get();
		_counter = other.getCounter();
		if (_counter)
			++(*_counter);
	}
	/**
	 * \brief Default copy constructor.
	 *
	 * U pointer should be converted to T pointer.
	 *
	 * \param other Other pointer to copy from.
	 */
	template <typename U>
	SharedPtr(SharedPtr<U> const& other)
	{
		_ptr = other.get();
		_counter = other.getCounter();
		if (_counter)
			++(*_counter);
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~SharedPtr()
	{
		if (_ptr)
		{
			--(*_counter);
			if (*_counter == 0)
			{
				delete _ptr;
				delete _counter;
			}
		}
	}

	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other pointer to assign from.
	 */
	SharedPtr & operator=(SharedPtr const& other)
	{
		if (_ptr != other.get())
			SharedPtr(other).swap(*this);
		return *this;
	}

	/**
	 * \brief Resets the pointer to default.
	 *
	 * This method resets the pointer to the default constructor.
	 */
	void reset()
	{
		SharedPtr().swap(*this);
	}
	/**
	 * \brief Resets the pointer to the given one.
	 *
	 * This method resets the pointer to the given one.
	 *
	 * \param otherPtr Other pointer to reset from.
	 */
	void reset(T * otherPtr)
	{
		SharedPtr(otherPtr).swap(*this);
	}

	/**
	 * \brief Default deference operator.
	 * 
	 * \returns a reference to the pointer hold.
	 */
	T & operator*() const
	{
		return *get();
	}

	/**
	 * \brief Default arrow operator.
	 *
	 * \returns the pointer hold.
	 */
	T * operator->() const
	{
		return get();
	}

	/**
	 * \brief Gets the pointer hold.
	 *
	 * \returns the pointer hold.
	 */
	inline T * get() const
	{
		return _ptr;
	}

	/**
	 * \brief Gets the pointer hold.
	 *
	 * \returns the pointer hold.
	 */
	template <typename U>
	inline U * get() const
	{
		U & tmp = dynamic_cast<U &>(*_ptr);
		return &tmp;
	}

	/**
	 * \brief Gets a reference to the pointer hold.
	 *
	 * \returns the pointer hold.
	 */
	inline T & get_ref() const
	{
		return *_ptr;
	}

	/**
	 * \brief Gets a reference to the pointer hold.
	 *
	 * \returns the pointer hold.
	 */
	template <typename U>
	inline U & get_ref() const
	{
		U & tmp = dynamic_cast<U &>(*_ptr);
		return tmp;
	}

	/**
	 * \brief Gets the counter pointer hold.
	 *
	 * \returns the counter pointer hold.
	 */
	inline int * getCounter() const
	{
		return _counter;
	}

	/**
	 * \brief Swaps between pointers.
	 *
	 * This method swap the contents between this pointer and
	 * the other pointer.
	 *
	 * \param other Other pointer to swap to.
	 */
	void swap(SharedPtr & other)
	{
		{
			T * tmp = _ptr;
			_ptr = other.get();
			other._ptr = tmp;
		}
		{
			int * tmp = _counter;
			_counter = other.getCounter();
			other._counter = tmp;
		}
	}

	/**
	 * \brief Compare function.
	 *
	 * This method determine the order criterion.
	 *
	 * \param rhs Right hand side object to compare.
	 *
	 * \return 0 on equal objects, >0 if this is greater and <0
	 * if it's less.
	 */
	int compare(SharedPtr const& rhs) const
	{
		if (_ptr == rhs.get())
			return 0;
		else
			return _ptr - rhs.get();
	}

  /**
   * \brief Default equal operator.
   *
   * Compares if the pointers hold are equal.
   *
   * \param rhs Right hand side object.
   */
  inline bool operator==(SharedPtr<T> const& rhs) const
  {
    return compare(rhs) == 0;
  }
  /**
   * \brief Default less operator.
   *
   * Compares if the pointers hold are less than.
   *
   * \param rhs Right hand side object.
   */
  inline bool operator<(SharedPtr<T> const& rhs) const
  {
    return compare(rhs) < 0;
  }

private:
	T * _ptr; /** Pointer hold. */
	int * _counter; /** Reference count for the pointer. */
};

#endif // SHAREDPTR_H_INCLUDED