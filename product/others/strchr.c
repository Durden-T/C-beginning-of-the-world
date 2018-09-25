char* strchr(char *s, char c)
{
    while(*s != '\0' && *s != c)
    {
        ++s;
    }
    return *s==c ? s : NULL;
}