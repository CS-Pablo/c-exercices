/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif-palindrome.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:22:25 by csauron           #+#    #+#             */
/*   Updated: 2025/03/19 04:10:10 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nettoyer_chaine(char *chaine, char *chaine_nettoyee)
{
    int j = 0;
    for (int i = 0; chaine[i] != '\0'; i++)
    {
        if (isalpha(chaine[i]))
        {
            chaine_nettoyee[j++] = tolower(chaine[i]);
        }
    }
    chaine_nettoyee[j] = '\0';
}

int est_palindrome(char *chaine)
{
    int debut = 0;
    int fin = strlen(chaine) - 1;

    while (debut < fin)
    {
        if (*chaine++ != chaine[fin])
        {
            return 0;
        }
        chaine++;
        fin--;
    }
    return 1;
}

int main()
{
    char chaine[100], chaine_nettoyee[100];

    printf("Entrez une phrase ou un mot : ");
    fgets(chaine, sizeof(chaine), stdin);
    chaine[strcspn(chaine, "\n")] = 0;

    nettoyer_chaine(chaine, chaine_nettoyee);

    if (est_palindrome(chaine_nettoyee))
    {
        printf("✅ \"%s\" est un palindrome.\n", chaine);
    }
    else
    {
        printf("❌ \"%s\" n'est pas un palindrome.\n", chaine);
    }

    return 0;
}
