void TrimRight(char* s)
{
    if (s == nullptr) return; 
    char* first_space = s; 
    for (; *s ; s++) 
    {
        if (*s != ' ')
        {
            first_space = s + 1;
        }
    }
    *first_space = 0;
}