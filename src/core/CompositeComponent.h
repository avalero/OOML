/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License (LGPL) as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License (LGPL) for more details.
*
*    You should have received a copy of the GNU Lesser General Public License (LGPL)
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

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
