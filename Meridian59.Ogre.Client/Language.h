/*
Copyright (c) 2012-2013 Clint Banzhaf
This file is part of "Meridian59 .NET".

"Meridian59 .NET" is free software:
You can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

"Meridian59 .NET" is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with "Meridian59 .NET".
If not, see http://www.gnu.org/licenses/.
*/

namespace LANGSTR
{
	enum Enum
	{
		USERNAME	= 0,
		PASSWORD	= 1,
		CONNECT		= 2,
		OPTIONS		= 3
	};
}

namespace LANGSTR_WINDOW_TITLE
{
	enum Enum
	{
		WELCOME		= 0,
		SPELLS		= 1,
		SKILLS		= 2,
		ACTIONS		= 3,
		INVENTORY	= 4,
		AMOUNT		= 5,
		TRADE		= 6,
		OPTIONS		= 7
	};
}

namespace LANGSTR_TOOLTIP_MOOD
{
	enum Enum
	{
		HAPPY	= 0,
		NEUTRAL = 1,
		SAD		= 2,
		ANGRY	= 3
	};
}

const char* GetLangLabel(const LANGSTR::Enum ID);
const char* GetLangWindowTitle(const LANGSTR_WINDOW_TITLE::Enum ID);
const char* GetLangTooltipMood(const LANGSTR_TOOLTIP_MOOD::Enum ID);
