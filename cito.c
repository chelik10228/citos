#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

main() {
	char buf[128];
	fputs("\033[H\033[2J", stdout);
	puts("[1 sec] Loading CitOS...");
	sleep(1);
	puts("[1 sec] Loading commands...");
	sleep(1);
	puts("Welcome to \033[32mCitOS\033[0m");
	while (1) {
		fputs("> ", stdout);
		fgets(buf, 128, stdin);
		if (strncmp(buf, "help", 4) == 0) {
			puts("1. help - show help menu");
			puts("2. puttest - test of 'puts'");
			puts("3. cifetch - information of the system");
			puts("4. echo - output text");
			puts("5. inc - increment the 0 number");
			puts("6. exit - exit from os");	
		}
		else if (strncmp(buf, "puttest", 7) == 0) {
			puts("This is a test of 'puts'.");
		}
		else if (strncmp(buf, "cifetch", 7) == 0) {
			puts("-----------        | OS Name: CitoOS");
			puts("|         |        | OS Version: 1.0");
			puts("|         |        | Language: C");
			puts("-----------        | Developer: Luxidev");
			puts("                   | Release Date: 2025-08-01");
		}
		else if (strncmp(buf, "echo ", 5) == 0) {
			printf(buf + 5);
		}
		else if (strncmp(buf, "exit", 4) == 0) {
			return 0;
		}
		else if (strncmp(buf, "inc", 3) == 0) {
			int x = 0;
			printf("Increment: %d\n", ++x);
		}
		else {
			puts("Bad command.");
		}
	}
}
