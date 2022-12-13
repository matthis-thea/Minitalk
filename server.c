#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void affichage(int pid)
{
	(void) pid;

	printf("Connexion etablit au serveur\n");
}

int main(void)
{
	int	pid;

	pid = getpid();
	printf("Serveur ouvert:\n");
	printf("Voici le PID du serveur %d\n", pid);
	signal(SIGUSR1 ,&affichage);
	signal(SIGUSR2, &affichage);
}