#include "SecondaryFunction.h"
#include "drysolid.hpp"


void saveTo(std::ofstream &file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream &file, const Printable& printable)
{
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream &file, const Printable& printable)
{
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream &file, const Printable& printable)
{
    saveTo(file, printable, Data::Format::kText);
}

int main(int argc, char** argv)
{
	printHeader(L"Принципы DRY и SOLID");
    
	
	
	std::wcout << "\n";
	return 0;
}
