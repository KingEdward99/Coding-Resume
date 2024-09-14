package Transit;

import lombok.Data;
import lombok.NoArgsConstructor;
import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Data
@NoArgsConstructor
@Document("riders")
public class Rider {


    @Id
    private ObjectId id;


    private String startAddress;

    public Rider (String startAddress) {
        this.startAddress = startAddress;
    }



}
