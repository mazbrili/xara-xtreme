// $Id$
/* @@tag:xara-cn@@ DO NOT MODIFY THIS LINE
================================XARAHEADERSTART===========================
 
               Xara LX, a vector drawing and manipulation program.
                    Copyright (C) 1993-2006 Xara Group Ltd.
       Copyright on certain contributions may be held in joint with their
              respective authors. See AUTHORS file for details.

LICENSE TO USE AND MODIFY SOFTWARE
----------------------------------

This file is part of Xara LX.

Xara LX is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as published
by the Free Software Foundation.

Xara LX and its component source files are distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with Xara LX (see the file GPL in the root directory of the
distribution); if not, write to the Free Software Foundation, Inc., 51
Franklin St, Fifth Floor, Boston, MA  02110-1301 USA


ADDITIONAL RIGHTS
-----------------

Conditional upon your continuing compliance with the GNU General Public
License described above, Xara Group Ltd grants to you certain additional
rights. 

The additional rights are to use, modify, and distribute the software
together with the wxWidgets library, the wxXtra library, and the "CDraw"
library and any other such library that any version of Xara LX relased
by Xara Group Ltd requires in order to compile and execute, including
the static linking of that library to XaraLX. In the case of the
"CDraw" library, you may satisfy obligation under the GNU General Public
License to provide source code by providing a binary copy of the library
concerned and a copy of the license accompanying it.

Nothing in this section restricts any of the rights you have under
the GNU General Public License.


SCOPE OF LICENSE
----------------

This license applies to this program (XaraLX) and its constituent source
files only, and does not necessarily apply to other Xara products which may
in part share the same code base, and are subject to their own licensing
terms.

This license does not apply to files in the wxXtra directory, which
are built into a separate library, and are subject to the wxWindows
license contained within that directory in the file "WXXTRA-LICENSE".

This license does not apply to the binary libraries (if any) within
the "libs" directory, which are subject to a separate license contained
within that directory in the file "LIBS-LICENSE".


ARRANGEMENTS FOR CONTRIBUTION OF MODIFICATIONS
----------------------------------------------

Subject to the terms of the GNU Public License (see above), you are
free to do whatever you like with your modifications. However, you may
(at your option) wish contribute them to Xara's source tree. You can
find details of how to do this at:
  http://www.xaraxtreme.org/developers/

Prior to contributing your modifications, you will need to complete our
contributor agreement. This can be found at:
  http://www.xaraxtreme.org/developers/contribute/

Please note that Xara will not accept modifications which modify any of
the text between the start and end of this header (marked
XARAHEADERSTART and XARAHEADEREND).


MARKS
-----

Xara, Xara LX, Xara X, Xara X/Xtreme, Xara Xtreme, the Xtreme and Xara
designs are registered or unregistered trademarks, design-marks, and/or
service marks of Xara Group Ltd. All rights in these marks are reserved.


      Xara Group Ltd, Gaddesden Place, Hemel Hempstead, HP2 6EX, UK.
                        http://www.xara.com/

=================================XARAHEADEREND============================
 */
/*
 * */

// Definition of Selection messages

#ifndef INC_SELMSG
#define INC_SELMSG


/*********************************************************************************************
>	class SelChangingMessage : public Msg

	Author:		Jason_Williams (Xara Group Ltd) <camelotdev@xara.com>
	Created:	11/5/94
	Purpose:	This message is sent at the end of all operations which have changed the
				selection.
				
				It is generated by Application::UpdateSelection() and SelRange::Update()
				when they are called, which includes such things as a document change
				altering the selection.

	SeeAlso:	SelRange; Application

*********************************************************************************************/

class SelChangingMsg : public Msg
{
	CC_DECLARE_DYNAMIC(SelChangingMsg)

public:

	// Messages are sent on (after!) these events.
	// Note attribute changes are divided into two groups Colour attribute changes and
	//	non-colour attribute changes. Recognising this major division between attributes (colours
	//	change more frequently than other attributes) allows UI redraw to be somewhat optimised.
	// 	Sometimes it may be necessary to send both a COLOURATTCHANGED and a NONCOLOURATTCHANGED
	//	message!
	enum SelectionState
	{
		SELECTIONCHANGED,				// The selection has changed (ie. nodes have been added/removed
										//	from the Selection).
		COLOURATTCHANGED,				// An attribute in the selection to do with colours in some way has changed
		NONCOLOURATTCHANGED,			// An attribute in the selection not to do with colours has changed
		NODECHANGED,					// At least one of the nodes in the selection has changed
										// NOTE! This means that its bounds may have changed
		EFFECTSTACKCHANGED				// An effect/effects applied to the selection has changed
		// Cor! Lots of ways the selection can change, huh?!
	};

	
	SelectionState State;	   			// The state, as defined above
	BOOL InDifferentDocument;			// Flag indicating the selection has changed
										// to a different document than the last
										// SelChangingMsg was for.

										// Constructor
	SelChangingMsg(SelectionState NewState, BOOL DiffDoc=FALSE)
			: State(NewState), InDifferentDocument(DiffDoc)
			{ /* empty */ }
};

#endif
