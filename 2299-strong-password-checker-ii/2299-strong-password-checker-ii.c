bool strongPasswordCheckerII(char * password){
     int n = strlen(password) ;
    if(n < 8)
        return false ;
    int status = 0; 
    char* special = "!@#$%^&*()-+" ;
    int n2 = strlen(special) ;
    for(int i = 0; i < n; i++){
        if((i > 0) && (password[i] == password[i-1]))
            return false ;
        if(password[i] >= 'a' && password[i] <= 'z')
            status |=  1 ;
        else if(password[i] >= 'A' && password[i] <= 'Z')
            status |= 2 ;
        else if(password[i] >= '0' && password[i] <= '9')
            status |= 4 ;
        else{
            if(status & 8)
                continue ;
            for(int j = 0; j < n2; j++){
                if(password[i] == special[j]){
                    status |= 8 ;
                    break ;
                }
            }
        }

    }
    if(status == 15)
        return true ;
    else
        return false ;

}