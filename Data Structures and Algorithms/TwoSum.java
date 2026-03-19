// Learning about hash maps
// This hash map assigns names to different specializations using hash maps

import java.util.HashMap;

public class TwoSum {
    public static void main (String[] args )
    {
       
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

    
        System.out.print(BulldogCodersDirectory); 

    }
}