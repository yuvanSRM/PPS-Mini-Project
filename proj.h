void write(char arr[]){
    FILE *file = fopen("results.txt","w");
    fprintf(file,"%s\n",arr);
    fclose(file);
}