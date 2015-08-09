//imports required packages
var ObjectID = require('mongodb').ObjectID;

//defines collection constructor method
CollectionDriver = function(db) {
    this.db = db;
};

//db.collection(name,callback) fetches the collection object and returns the collection 
//— or an error — to the callback.

CollectionDriver.prototype.getCollection = function(collectionName, callback) {
    this.db.collection(collectionName, function(error, the_collection) {
	    if( error ) callback(error);
	    else callback(null, the_collection);
	});
};

CollectionDriver.prototype.findAll = function(collectionName, callback) {
    this.getCollection(collectionName, function(error, the_collection) { //A
      if( error ) callback(error);
      else {
        the_collection.find().toArray(function(error, results) { //B
          if( error ) callback(error);
          else callback(null, results);
        });
      }
    });
};

CollectionDriver.prototype.findItem = function(collectionName, name, callback) {
    this.getCollection(collectionName, function(error, the_collection) { //A
      if( error ) callback(error);
      else {
        the_collection.find({title:name}).toArray(function(error, results) { //B
          if( error ) callback(error);
          else callback(null, results);
        });
      }
    });
};


CollectionDriver.prototype.get = function(collectionName, id, callback) { //A
    this.getCollection(collectionName, function(error, the_collection) {
        if (error) callback(error);
        else {
            var checkForHexRegExp = new RegExp("^[0-9a-fA-F]{24}$"); //B
            //console.log("OBJECT ID : " + ObjectID(name))
            if (!checkForHexRegExp.test(id)) callback({error: "invalid id"});
            else the_collection.findOne({'_id':ObjectID(id)}, function(error,doc) { //C
                if (error) callback(error);
                else callback(null, doc);
            });
        };
    });
};

//save new object
CollectionDriver.prototype.save = function(collectionName, obj, callback) {
    this.getCollection(collectionName, function(error, the_collection) { //A
      if( error ) callback(error)
      else {
        obj.created_at = new Date(); //B
        the_collection.insert(obj, function() { //C
          callback(null, obj);
                  	console.log("collection inserted");

        });
      }
    });
};

//update a specific object
CollectionDriver.prototype.update = function(collectionName, obj, entityId, callback) {
    this.getCollection(collectionName, function(error, the_collection) {
        if (error) callback(error);
        else {
            obj._id = ObjectID(entityId); //A convert to a real obj id
            obj.updated_at = new Date(); //B
            the_collection.save(obj, function(error,doc) { //C
                if (error) callback(error);
                else callback(null, obj);
            });
        }
    });
};

//delete a specific object
CollectionDriver.prototype.delete = function(collectionName, entityId, callback) {
    this.getCollection(collectionName, function(error, the_collection) { //A
        if (error) callback(error);
        else {
            the_collection.remove({'_id':ObjectID(entityId)}, function(error,doc) { //B
                if (error) callback(error);
                else callback(null, doc);
            });
        }
    });
};

// app.put('/:collection/:entity', function(req, res) { //A
//     var params = req.params;
//     var entity = params.entity;
//     var collection = params.collection;
//     if (entity) {
//        collectionDriver.update(collection, req.body, entity, function(error, objs) { //B
//           if (error) { res.send(400, error); }
//           else { res.send(200, objs); } //C
//        });
//    } else {
//        var error = { "message" : "Cannot PUT a whole collection" };
//        res.send(400, error);
//    }
// });

//This line declares the exposed, or exported, entities to other applications that list collectionDriver.js as a required module.
exports.CollectionDriver = CollectionDriver;

