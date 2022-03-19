#include "BaseGameEntity.h"
#include <cassert>



int BaseGameEntity::m_iNextValidID = 0;



//----------------------------- SetID -----------------------------------------
//
//  this must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseGameEntity::SetID(int val)
{
  //make sure the val is equal to or greater than the next available ID
  assert ( (val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
  
  /*
  

This is a common trick when using assert macro from <cassert>. The macro fails if its argument evaluates to false, then the program exits without any readable diagnostic message (usually just a line number, file and stringified condition of the assert()).

That is, to improve the diagnostic message, one can hack the boolean expression by adding a string literal that will be printed out together with the condition:

assert((val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
//                                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The string literal always evaluates to boolean true (because it is a pointer), hence, it makes no impact to the condition itself. However, when the first operand of && condition fails, then the entire condtion is not satisfied (due to its logic) and assert ends the program, printing out:

Assertion failed: (val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID"
Then, seeing this message, one can know that the provided ID for SetID method was not valid.
*/

  m_ID = val;
    
  m_iNextValidID = m_ID + 1;
}
