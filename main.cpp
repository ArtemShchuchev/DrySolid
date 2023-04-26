#include "SecondaryFunction.h"
#include "drysolid.hpp"

/*
    Принцип открытости/закрытости
    В случае добавления новых форматов, придется изменять код saveTo



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
*/

void saveTo(std::wostream& file, const Format& printable)
{
    file << ansi2wide(printable.formatting()) << std::endl;
}

int main(int argc, char** argv)
{
	printHeader(L"Принципы DRY и SOLID");
    
    std::wofstream file;
    file.open(L"test.txt", std::ios_base::app);

    FormatAsHTML html("format HTML");
    saveTo(std::wcout, html);
    saveTo(file, html);
    saveTo(std::wcerr, html);

    FormatAsText text("format Text");
    saveTo(std::wcout, text);
    saveTo(file, text);
    saveTo(std::wcerr, text);

    FormatAsJSON json("format JSON");
    saveTo(std::wcout, json);
    saveTo(file, json);
    saveTo(std::wcerr, json);
	
	std::wcout << "\n";
	return 0;
}
