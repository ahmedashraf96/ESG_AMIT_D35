int mul = 1;

int fact(int x)
{
    if(x > 0)
    {
        mul = x * fact(x-1);
    }
    else
    {
        /*Do nothing*/
    }

    return mul;
}