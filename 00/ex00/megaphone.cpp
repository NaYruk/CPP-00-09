#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int j = 1; argv[j] != NULL; j++)
	{
		for (int i = 0; argv[j][i] != '\0'; i++)
		{
			std::cout << static_cast<char>(std::toupper(argv[j][i]));
		}
	}
	std::cout << std::endl;
	return 0;
}