#include "form.h"

Form::Form()
{
}

Form::Form(Point p)
{
    this->p = p;
}



int Form::perimeter()
{
    return 0;
}

int Form::surface()
{
    return 0;
}

void Form::operator+=(Form const& f)
{
    this->p += f.p;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os <<"P : "<< f.getPoint() << std::endl;
    return os;
}