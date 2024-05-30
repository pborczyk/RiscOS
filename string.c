int strlen(char* str) {
    int size = 0;
    int strpos = 0;
    while (str[strpos] != '\0') {
        size++;
        strpos++;
    }
    return size;
}

void strrev (char* str)  {
    //we swap till the two pointers meet or pass by each other, this way we will reverse string in place
    char* begging_pointer = str;
    char* end_pointer = str + strlen(str) - 1;
    char tmp;
    while (begging_pointer != end_pointer && end_pointer > begging_pointer)
    {
        tmp = *begging_pointer;
        *begging_pointer = *end_pointer;
        *end_pointer = tmp;
        begging_pointer++;
        end_pointer--;
    }
}