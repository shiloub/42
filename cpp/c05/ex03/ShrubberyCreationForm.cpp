#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 145, 137), _target("random"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : Form(cpy), _target(cpy._target){}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    if (this != &rhs)
    {
      this->_target = rhs._target;
      this->set_signed(rhs.getSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execAction() const 
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream outFile(fileName.c_str());
	if (!outFile)
		std::cout << "cant create outfile\n";
    outFile << "          .     .  .      +     .      .          .\n\
     .       .      .     #       .           .\n\
        .      .         ###            .      .      .\n\
      .      .   \"#:. .:##\"##:. .:#\"  .      .\n\
          .      . \"####\"###\"####\"  .\n\
       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n\
  .             \"#########\"#########\"        .        .\n\
        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n\
     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n\
                .\"##\"#####\"#####\"##\"           .      .\n\
    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n\
      .     \"#######\"##\"#####\"##\"#######\"      .     .\n\
    .    .     \"#####\"\"#######\"\"#####\"    .      .\n\
            .     \"      000      \"    .     .\n\
       .         .   .   000     .        .       .\n\
.. .. ..................O000O........................ ......\n";
}