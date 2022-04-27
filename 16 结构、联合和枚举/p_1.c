#include <stdio.h>

struct dailing_code
{
	char* country;
	int code;
};

int main(void)
{
    int code;
    const struct dailing_code country_codes[] = {
        {"Argentina",            54}, {"Bangladesh",     889},
        {"Brazil",               55}, {"Burma (Myanmar)", 95},
        {"China",                86}, {"Colombia",        57},
        {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
        {"Ethiopia",            251}, {"France",          33},
        {"Germany",              49}, {"India",           91},
        {"Indonesia",            62}, {"Iran",            98},
        {"Italy",                39}, {"Japan",           81},
        {"Mexico",               52}, {"Nigeria",        234},
        {"Pakistan",             92}, {"Philippines",     63},
        {"Poland",               48}, {"Russia",           7},
        {"South Africa",         27}, {"South Korea",     82},
        {"Spain",                34}, {"Sudan",          249},
        {"Thailand",             66}, {"Turkey",          90},
        {"Ukraine",             380}, {"United Kingdom",  44},
        {"United States",         1}, {"Vietnam",         84}
    };

    printf("Enter an international dialing code: ");
    scanf("%d", &code);
    for (int i = 0; i < 32; i++)
        if (country_codes[i].code == code)
        {
            printf("%d is the code for %s\n", country_codes[i].code, country_codes[i].country);
            return 0;
        }
    printf("Error: %d is not a valid country code.\n", code);
    return 0;
}