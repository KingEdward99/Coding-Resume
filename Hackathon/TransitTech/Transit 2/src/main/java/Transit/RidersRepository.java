package Transit;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;

@Repository
public interface RidersRepository extends MongoRepository<Rider, ObjectId> {

    public ArrayList<Rider> findAll();

}
