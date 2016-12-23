/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 02:30:13 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/13 02:43:30 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>

int main( void )
{
	char     ch = 'h', 
			 *string = "computer";
	wchar_t  wch = L'w', 
			 *wstring = L"Unicode";
	int      count = -9234;
	double   fp = 251.7366;

	printf( "Integer formats:\n"
			"   Decimal: %d  Justified: %.6d  "
			"Unsigned: %u\n",
			count, count, count);
	printf( "Decimal %d as:\n   Hex: %Xh  "
			"C hex: 0x%x  Octal: %o\n",
			count, count, count, count );
	printf( "Digits 10 equal:\n   Hex: %i  "
			"Octal: %i  Decimal: %i\n",
			0x10, 010, 10 );
	printf("Characters in field (1):\n"
			"%10c%c%5C%5lc\n",
			ch, ch, wch, wch);
	wprintf(L"Characters in field (2):\n"
			L"%10C%5hc%5c%5lc\n",
			ch, ch, wch, wch);
	printf("Strings in field (1):\n%25s\n"
			"%25.4s\n   %S%25.3ls\n",
			string, string, wstring, wstring);
	wprintf(L"Strings in field (2):\n%25S\n"
			L"%25.4hs\n   %s%25.3ls\n",
			string, string, wstring, wstring);
	printf("Real numbers:\n   %f %.2f %e %E\n",
			fp, fp, fp, fp );
	printf( "\nAddress as:   %p\n", &count);
}
