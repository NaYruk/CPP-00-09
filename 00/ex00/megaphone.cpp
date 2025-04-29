#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 0;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (argv[++i])
    {
        j = -1;
        while(argv[i][++j] != '\0')
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
    }
    std::cout << std::endl;
    return 0;
}
