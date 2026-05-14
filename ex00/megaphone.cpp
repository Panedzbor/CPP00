#include <iostream>
#include <cctype>

static void print_capitalized(int argc, char *argv[]);
static void capitalize(char *str);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    print_capitalized(argc, argv);
    return (0);
}

static void print_capitalized(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        capitalize(argv[i]);
        std::cout << argv[i];
    }
    std::cout << std::endl;
}

static void capitalize(char *str)
{
    for (int i = 0; str[i] > 0; i++)
        str[i] = std::toupper(str[i]);
}