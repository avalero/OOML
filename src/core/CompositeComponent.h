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

#ifndef COMPOSITECOMPONENT_H_INCLUDED
#define COMPOSITECOMPONENT_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/Component.h>
#include <core/CompositeObject.h>
#include <core/IndentWriter.h>

#include <algorithm>
#include <vector>

/**
 * \brief Composite component interface.
 *
 * This class provides a composite component interface.
 */
class CompositeComponent : public Component
{
public:
	/**
	 * \brief Default constructor.
	 */
	CompositeComponent() :
		Component(),
		_decoratedComposite(0)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 */
	CompositeComponent(SharedPtr<CompositeObject> const& decorated) :
		 Component(),
		_decoratedComposite(0)
	{
		set(SharedPtr<AbstractObject>(decorated));
	}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other component to copy from.
	 */
	CompositeComponent(CompositeComponent const& other)
	{
		set(other.get());
	}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other component to assign from.
	 */
	CompositeComponent & operator=(CompositeComponent const& other)
	{
		set(other.get());
		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~CompositeComponent() {}

	/**
	 * \brief Adds a component to the composite.
	 *
	 * This method adds a component pointer to the composite component.
	 *
	 * \param component Component to be added.
	 */
	virtual void addComponent(Component const& component)
	{
		_decoratedComposite->addObject(component.get());
	}
	/**
	 * \brief Removes a component from the composite.
	 *
	 * This method removes a component pointer from the composite component.
	 *
	 * \param component Component to be removed.
	 */
	virtual void removeComponent(Component const& component)
	{
		_decoratedComposite->removeObject(component.get());
	}

	/**
	 * \brief Adds a component with insertor syntax.
	 *
	 * This methods adds a component through the insertor interface.
	 *
	 * \param component Component to be inserted.
	 */
	virtual CompositeComponent & operator<<(Component const& component)
	{
		addComponent(component);
		return *this;
	}

	/**
	 * \brief Set the internally hold pointer.
	 *
	 * \param value New interanlly hold object pointer.
	 */
	virtual void set(SharedPtr<AbstractObject> const& value)
	{
		Component::set(value);
		updatePointer();
	}

protected:

	CompositeObject * _decoratedComposite; /** Decorated composite object. */

private:
	/**
	 * \brief Updates the internal composite pointer based in the decorated original.
	 */
	void updatePointer()
	{
		_decoratedComposite = dynamic_cast<CompositeObject *>(get().get());
		// TODO: Check for problems...
	}


};

#endif // COMPOSITECOMPONENT_H_INCLUDED
