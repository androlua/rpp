/*
split、快排、二分
*/

import "ralgo.h"

main
{
	rbuf<rstr> v
	r_split<rstr>('321;1343;fj242i;12',';',v)
	for i in v
		v[i].printl
	putsl
	
	r_qsort<rstr>(v)
	for i in v
		v[i].printl
	putsl
	
	v.get(r_find_pos_b<rstr>(v,'12')).printl
	
	'1234'.find('34').printl
}
