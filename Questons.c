Q1)Road Repair
/*
 * Complete the 'getMinCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY crew_id
 *  2. INTEGER_ARRAY job_id
 */
int Compfunc(int*N1,int*N2)
{
    return  ((*N1)-(*N2));
}
#define My_ABS(X)  ((X)*(((2*X)+1)%2))
long getMinCost(int crew_id_count, int* crew_id, int job_id_count, int* job_id) 
{
    long Min=0;
    long Counter=0;
    long Temp=0;
    qsort(crew_id, crew_id_count, sizeof(int),Compfunc);
    qsort(job_id, job_id_count, sizeof(int),Compfunc);
    for(;Counter<crew_id_count;Counter++)
    {
        Temp = crew_id[Counter] - job_id[Counter];
        Temp = My_ABS(Temp);
        Min += Temp;
    }
    
    
    return  (Min);
}
/****************************************************/

Q2)parallel processing


/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY files
 *  2. INTEGER numCores
 *  3. INTEGER limit
 */

int CompFunc(int*Num1,int*Num2)
{
    return ((*Num1) - (*Num2));
}

long minTime(int files_count, int* files, int numCores, int limit) 
{
    long Min=0;
    long Counter=0;
    long Temp=0;
    qsort(files, files_count, sizeof(int), CompFunc);
    
        for(Counter=files_count-1;(Counter>=0) ;Counter--)
        {
            if((0 == files[Counter]%numCores)&& (limit))
            {
                Temp+= files[Counter]/numCores;
                limit--;   
            }
            else
            {
                Min += files[Counter];
            }
        }
        Min += Temp;

    
    return (Min);
}