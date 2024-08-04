#include "globalutils.hpp"

void GlobalUtils::spc(progressbar &bar)
{
    bar.set_todo_char(" ");
    bar.set_done_char("█");
    bar.set_opening_bracket_char("[");
    bar.set_closing_bracket_char("]");
}