/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef ROCKETCONTROLSINPUTTYPE_H
#define ROCKETCONTROLSINPUTTYPE_H

#include "../../Include/Rocket/Core/String.h"
#include "../../Include/Rocket/Core/Event.h"
#include "../../Include/Rocket/Core/Types.h"

namespace Rocket {
namespace Controls {

class ElementFormControlInput;

/**
	An interface for a input type handler used by ElementFormControlInput. A concrete InputType object handles the
	functionality of an input element.

	@author Peter Curry
 */

class InputType
{
public:
	InputType(ElementFormControlInput* element);
	virtual ~InputType();

	/// Returns a string representation of the current value of the form control.
	/// @return The value of the form control.
	virtual Rocket::Core::String GetValue() const;
	/// Returns if this value should be submitted with the form.
	/// @return True if the form control is to be submitted, false otherwise.
	virtual bool IsSubmitted();

	/// Called every update from the host element.
	virtual void OnUpdate();

	/// Called every render from the host element.
	virtual void OnRender();

	/// Called every time the host element's size changes.
	virtual void OnResize();

	/// Checks for necessary functional changes in the control as a result of changed attributes.
	/// @param[in] changed_attributes The list of changed attributes.
	/// @return True if no layout is required, false if the layout needs to be dirtied.
	virtual bool OnAttributeChange(const Core::ElementAttributes& changed_attributes);
	/// Called when properties on the control are changed.
	/// @param[in] changed_properties The properties changed on the element.
	virtual void OnPropertyChange(const Core::PropertyNameList& changed_properties);

	/// Called when the element is added into a hierarchy.
	virtual void OnChildAdd();
	/// Called when the element is removed from a hierarchy.
	virtual void OnChildRemove();

	/// Checks for necessary functional changes in the control as a result of the event.
	/// @param[in] event The event to process.
	virtual void ProcessDefaultAction(Core::Event& event) = 0;

	/// Sizes the dimensions to the element's inherent size.
	/// @return True.
	virtual bool GetIntrinsicDimensions(Rocket::Core::Vector2f& dimensions) = 0;

protected:
	ElementFormControlInput* element;
};

}
}

#endif
