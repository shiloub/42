#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat paul("Paul", 146);
	Bureaucrat noob("noob", 150);
	ShrubberyCreationForm form("buisson");
	
	paul.executeForm(form);  //   paul essaye d'exec mais le formulaire n'est pas signé
	paul.signForm(form);       // paul essaye de signer mais est trop bas d'un rang
	paul.increment();          // paul gagne le rang qui lui manque pour signer
	paul.signForm(form);       // paul peut signer
	paul.signForm(form);       // paul re-signe mais c deja signé : exception
	paul.executeForm(form);    // paul a signé mais est trop bas pour exec : nouvelle exception
	for (int i = 0; i < 8; i++)
		paul.increment();      // paul gagne 8 rangs pour avoir le droit d'exec(il faut 137)
	paul.executeForm(form); //    victoire il signe

	std::cout << "\n_______________________________\n";

	RobotomyRequestForm robot("caillou");
	PresidentialPardonForm pardon("xddl");
	Bureaucrat boss("guy martin", 1); // plus haut grade il a tout les droits

	boss.increment(); //impossible donc exception
	boss.signForm(robot); // il signe les deux formulaires
	boss.signForm(pardon);

	boss.executeForm(robot); // marche 50% du temps
	boss.executeForm(pardon); // marche tout le temps

}