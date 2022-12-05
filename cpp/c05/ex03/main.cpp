#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{


	Bureaucrat paul("Paul", 146);
	Bureaucrat noob("noob", 150);
	
	Intern someRandomIntern;
	Form* form;
	RobotomyRequestForm test("test");
	RobotomyRequestForm cpy(test);
	std::cout << cpy << std::endl;
	std::cout << "--------------------\n";
	form = someRandomIntern.makeForm("shrubbery creation", "Bender");

	if (form == NULL)
		return 0;
	
	paul.executeForm(*form);  //   paul essaye d'exec mais le formulaire n'est pas signé
	paul.signForm(*form);       // paul essaye de signer mais est trop bas d'un rang
	paul.increment();          // paul gagne le rang qui lui manque pour signer
	paul.signForm(*form);       // paul peut signer
	paul.signForm(*form);       // paul re-signe mais c deja signé : exception
	paul.executeForm(*form);    // paul a signé mais est trop bas pour exec : nouvelle exception
	for (int i = 0; i < 8; i++)
		paul.increment();      // paul gagne 8 rangs pour avoir le droit d'exec(il faut 137)
	paul.executeForm(*form); //    victoire il signe
	delete form;
	std::cout << "\n_______________________________\n";

	Form *robot;
	Form *pardon;
	Intern stagiaire;
	Form *rate;
	rate = stagiaire.makeForm("error", "random"); // erreur : error n est pas un nom de form
	robot = stagiaire.makeForm("robotomy request", "caillou");
	pardon = stagiaire.makeForm("presidential pardon", "xavier dupont de ligonnes");
	Bureaucrat boss("guy martin", 1); // plus haut grade il a tout les droits

	boss.increment(); //impossible donc exception
	boss.signForm(*robot); // il signe les deux formulaires
	boss.signForm(*pardon);

	boss.executeForm(*robot); // marche 50% du temps
	boss.executeForm(*pardon); // marche tout le temps
	delete robot;
	delete pardon;

}