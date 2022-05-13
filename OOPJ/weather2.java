import java.util.Scanner;

class WeatherReport{
    float highTemp;
    float lowTemp;
    float amountRain;
    float amountSnow;
    String date;
    
    WeatherReport(){
        getData();
    }
    WeatherReport(float high , float low, float rain ,float snow , String day){
        highTemp = high;
        lowTemp = low;
        amountRain = rain;
        amountSnow = snow;
        date = day;
    }
    void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the date : ");
        date = sc.nextLine();
        System.out.println("Enter the Highest Temperature : ");
        highTemp = sc.nextFloat();
        System.out.println("Enter the Lowest Temperature : ");
        lowTemp = sc.nextFloat();
        System.out.println("Enter the Amount of Rain : ");
        amountRain = sc.nextFloat();
        System.out.println("Enter the Amount of Snow : ");
        amountSnow = sc.nextFloat();
    }
    void printData(){
        System.out.println("Date\t\t HighestTemperature\t LowestTemperature\t Amount of Rain\t Amount of Snow\t");
        System.out.println(date +"\t\t" + highTemp + "\t\t\t" + lowTemp + "\t\t\t" + amountRain + "\t\t" + amountSnow);
    }
}


public class weather2 {
    static void findAvg(WeatherReport[] arr){
        int n = arr.length;
        float highTempAvg = 0;
        float lowTempAvg = 0;
        float rainAvg = 0;
        float snowAvg = 0;
        for(int i=0;i<arr.length;i++){
            highTempAvg += arr[i].highTemp;
            lowTempAvg += arr[i].lowTemp;
            rainAvg += arr[i].amountRain;
            snowAvg += arr[i].amountSnow;
        }
        highTempAvg = highTempAvg / n;
        lowTempAvg = lowTempAvg / n;
        rainAvg = rainAvg / n;
        snowAvg = snowAvg / n;
        System.out.println("The HighTemperature average is " + highTempAvg + "\nThe LowestTemperature average is " + lowTempAvg + "\nThe Amount rain average is " + rainAvg + "\nThe Amount snow average is " + snowAvg);
    }
    static void getMax(WeatherReport[] arr){
        float maxHigh = 0;
        float maxLow = arr[0].lowTemp;
        float maxRain = 0;
        float maxSnow = 0;
        for(int i=0;i<arr.length;i++){
            maxHigh = Math.max(maxHigh, arr[i].highTemp);
            maxLow = Math.min(maxLow, arr[i].lowTemp);
            maxRain = Math.max(maxRain , arr[i].amountRain);
            maxSnow = Math.max(maxSnow, arr[i].amountSnow);
        }
        System.out.println("The largest HighTemperature is " + maxHigh + "\nThe smallest LowestTemperature average is " + maxLow + "\nThe highest Amount rain is " + maxRain + "\nThe highest Amount snow is " + maxSnow);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String city;
        System.out.println("Enter the city name : ");
        city = sc.nextLine();
        System.out.println("Enter the details for weather report : ");
        WeatherReport[] arr;
        arr = new WeatherReport[5];
        float highTemp;
        float lowTemp;
        float amountRain;
        float amountSnow;
        String date;
        System.out.println("Enter the date : ");
        date = sc.nextLine();
        System.out.println("Enter the Highest Temperature : ");
        highTemp = sc.nextFloat();
        System.out.println("Enter the Lowest Temperature : ");
        lowTemp = sc.nextFloat();
        System.out.println("Enter the Amount of Rain : ");
        amountRain = sc.nextFloat();
        System.out.println("Enter the Amount of Snow : ");
        amountSnow = sc.nextFloat();
        arr[0] = new WeatherReport(highTemp , lowTemp , amountRain , amountSnow , date );
        for(int i=1;i<5;i++){
            arr[i] = new WeatherReport();
        }
        System.out.println("Weather Report");
        for(int i=0;i<5;i++){
            arr[i].printData();
        }
        findAvg(arr);
        getMax(arr);
    }
    
}
