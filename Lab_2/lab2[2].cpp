// A cpp program to find the area
#include<cstdio>
class Area{
    private:
    double length, breadth, width;

    public:
    Area() {
        length = 1;
        breadth = 1;
        width = 1;
    }

    double area_square(int length){
        return length*length;
        
    }
    double area_cube(int length){
        return 6*length*length;
        
    }
    double area_rectangle(int length, int breadth){
        return  length*breadth;
       
    }
    double area_cuboid(int length, int breadth, int width){
        return  2 * (length*breadth + breadth*width + width*length);
        

    }
};


int main(){
int choice, length, breadth, width;
Area obj;

while(true){
    printf("1. Area of a square\n");
    printf("2. Area of a cube\n");
    printf("3. Area of a rectangle\n");
    printf("4. Area of a cuboid\n");
    printf("Exiting....\n");
    printf("enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the length: ");
            scanf("%d", &length);

            if(length<= 0){
                printf("enter a valid number");
            break;}
            
            printf("the area of the square is: %f", obj.area_square(length));
            break;

        case 2:
            printf("Enter the length: ");
            scanf("%d", &length);
            if(length<= 0){
                printf("enter a valid number");
            break;}
            
            printf("The area of the cube is : %f\n", obj.area_cube(length));
            break;
        case 3:
            printf("Enter the length: ");
            scanf("%d", &length);
            printf("Enter the breadth: ");
            scanf("%d", &breadth); 
            if(length<= 0|| breadth<= 0){
                printf("enter a valid number"); 
            break;
            }  
            printf("The area of the rectangle is : %f", obj.area_rectangle(length, breadth));
            break;

        case 4:
            printf("Enter the length: ");
            scanf("%d", &length);
            printf("Enter the breadth: ");
            scanf("%d", &breadth); 
            printf("Enter the width: ");
            scanf("%d", &width);
            if(length<=0 || breadth<=0 || width<=0)  {
                printf("enter a valid number");
                break;}
            printf("The area of the cuboid is : %f", obj.area_cuboid(length, breadth, width));    
            break;

         case 5:
                printf("Exiting....\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;    
    }        
    }

return 0;}

