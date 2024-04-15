/*
GCD(M, N) 
M, N are the two integers of interest 
GCD returns the integer greatest common divisor 
if ( M < N ) then 
 

swap M and N 
end if 
if ( N = 0) then 
return M 
else 
quotient = M / N 
 

//NOTE: integer division 
 

remainder = M mod N 
return GCD( N, remainder ) 
end if 
*/