// Learning about hash maps

import java.time.temporal.ValueRange;
import java.util.HashMap;

public class TwoSum {
    public static void main (String[] args )
    {
        int[] array = {2, 5,7,11,19,21, 35}; 

        HashMap<String, String> BulldogCodersDirectory = new HashMap<>(); 
        BulldogCodersDirectory.put("Eddy", "Cybersecurity");
        BulldogCodersDirectory.put("Praise", "AI/ML");
        BulldogCodersDirectory.put("Melanie", "Data Science");
        BulldogCodersDirectory.put("Tobi", "Cybersecurity");  
        BulldogCodersDirectory.put("Daniel", "Software Engineering"); 
        BulldogCodersDirectory.put("Ahman", "Cybersecurity"); 
        BulldogCodersDirectory.put("Bryan", "Scripting");
        BulldogCodersDirectory.put("Jada", "Nursing"); 
        BulldogCodersDirectory.put("Nelson", "Product Design"); 
        BulldogCodersDirectory.put("Adeola", "Cybersecurity"); 
        BulldogCodersDirectory.put("Bariroh", "Software Engineering");

        string test = BulldogCodersDirectory.get("Ahman");

        System.out.print(BulldogCodersDirectory); 

        /* 
        Name : Grade
        {
            "Eddy": 90
            "Praise" : 85
            "James" : 78

        }
        */ 
    }
}