// int red = (int)(col.r * 255);
// int green = (int)(col.g * 255);
// int blue = (int)(col.b * 255);
// int a = red  << 16 | green << 8 | blue;
// float b = ((float)a) / 0xFFFFFF;
// return b;


bool closeTo(float value0, float value1)
{
    return (value0 <= (value1 + d)) && (value0 >= (value1 - d));
}

float d = 0.0001;
float res = 0;
res = col.r;

if (col.g > (0 + d) && col.g < (1 - d))
{
    res = color.g + 1;
}

if (col.b > (0 + d) && col.b < (1 - d))
{
    res = col.b + 2;
}

if(closeTo(col.b, 1)){
    res += 3;
}

return res / 3;

int intV = (int) (col[2] / (1/6)) ;



((float) ((int)(col[2]/ (1/6) )) ) / 6.f;

// if(closeTo(col.g, 1)){
//     res += 5;
// }






float zeroEq = 0.05;
float sum0 = col0.r + col0.g + col0.b;
float sum1 = col1.r + col1.g + col1.b;
float sum2 = col2.r + col2.g + col2.b;
float sum3 = col3.r + col3.g + col3.b;
float sum4 = col4.r + col4.g + col4.b;
float sum5 = col5.r + col5.g + col5.b;
float sum6 = col6.r + col6.g + col6.b;
float sum7 = col7.r + col7.g + col7.b;
if(sum0 < zeroEq 
|| sum1 < zeroEq 
|| sum2 < zeroEq 
|| sum3 < zeroEq 
|| sum4 < zeroEq 
|| sum5 < zeroEq 
|| sum6 < zeroEq 
|| sum7 < zeroEq) 
    return 0;
return 1;




float zeroEq = 0.05;
float threshold = .01f;
float origSum = orig.r + orig.g +orig.b;

if(origSum < zeroEq)
    return 0;

float sums[8];
int i = 0;

sums[i++] = col0.r + col0.g + col0.b;
sums[i++] = col1.r + col1.g + col1.b;
sums[i++] = col2.r + col2.g + col2.b;
sums[i++] = col3.r + col3.g + col3.b;
sums[i++] = col4.r + col4.g + col4.b;
sums[i++] = col5.r + col5.g + col5.b;
sums[i++] = col6.r + col6.g + col6.b;
sums[i++] = col7.r + col7.g + col7.b;

for (int i=0;i<8;i++){
    if(abs(origSum - sums[i]) > threshold)
        return 0;
}
return 1;





float zeroEq = 0.05;
float threshold = .01f;
float origSum = orig.r;

if(orig.b < zeroEq)
    return 0;

float sums[8];
int i = 0;

sums[i++] = col0.r;
sums[i++] = col1.r;
sums[i++] = col2.r;
sums[i++] = col3.r;
sums[i++] = col4.r;
sums[i++] = col5.r;
sums[i++] = col6.r;
sums[i++] = col7.r;

for (int i=0;i<8;i++){
    if(abs(origSum - sums[i]) > threshold)
        return 0;
}
return 1;






float zeroEq = 0.05;
float threshold = .01f;
float origSum = orig.r;

if(orig.b < zeroEq)
    return 0;

float sums[8];
int i = 0;

sums[i++] = col0.b;
sums[i++] = col1.b;
sums[i++] = col2.b;
sums[i++] = col3.b;
sums[i++] = col4.b;
sums[i++] = col5.b;
sums[i++] = col6.b;
sums[i++] = col7.b;

for (int i=0;i<8;i++){
    if(sums[i] < zeroEq)
        return 0;
}
return 1;