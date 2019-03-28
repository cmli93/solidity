/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * Optimisation stage that removes unused variables and functions.
 */

#pragma once

#include <libyul/optimiser/ASTWalker.h>
#include <libyul/YulString.h>

#include <map>
#include <set>

namespace yul
{
struct Dialect;

/**
 * Optimisation stage that removes unreachable code
 *
 * Unreachable code is any code within a block which is preceded by an
 * unconditional return, invalid, break, continue, selfdestruct or revert.
 *
 */
class DeadCodeEliminator: public ASTModifier, private ASTWalker
{
public:
	using ASTModifier::operator();
	void operator()(Block& _block) override;
	bool containsDeadCode(Block const& _block);
private:
	bool m_found_dead_code = true;

	void operator()(Block const& _block) override;
};

}
