//1
var http = require('http'),
    express = require('express'),
    path = require('path'), 
    MongoClient = require('mongodb').MongoClient,
	Server = require('mongodb').Server,
	CollectionDriver = require('./collectionDriver').CollectionDriver;
 
//2 
var app = express();
app.set('port', process.env.PORT || 3000); 
//specifies where the views live:
app.set('views', path.join(__dirname, 'views'));
//sets jade as as the view rendering engine
app.set('view engine', 'jade');

app.use(express.bodyParser());


//Line A above assumes the MongoDB instance is running locally 
 //on the default port of 27017. If you ever run a MongoDB server 
 //elsewhere you’ll have to modify these values, but leave them as-is 
 //for this tutorial.

var mongoHost = 'localHost'; //A
var mongoPort = 27017; 
var collectionDriver;

var mongoClient = new MongoClient(new Server(mongoHost, mongoPort)); //B
mongoClient.open(function(err, mongoClient) { //C
  if (!mongoClient) {
      console.error("Error! Exiting... Must start MongoDB first");
      process.exit(1); //D
  }
  var db = mongoClient.db("MyDatabase");  //E
  collectionDriver = new CollectionDriver(db); //F
  console.log(collectionDriver);
});

app.use(express.static(path.join(__dirname, 'public')));
 
app.get('/', function (req, res) {
  res.send('<html><body><h1>Hello World poop</h1></body></html>');
});

app.get('/:collection', function(req, res) { //A
   var params = req.params; //B
   collectionDriver.findAll(req.params.collection, function(error, objs) { //C
    	  if (error) { res.send(400, error); } //D
	      else { 
	          if (req.accepts('html')) { //E
    	          res.render('data.jade',{objects: objs, collection: req.params.collection}); //F
              } else {
	          res.set('Content-Type','application/json'); //G
                  res.send(200, objs); //H
              }
         }
   		});
});

app.get('/returnAll/:collection', function(req, res) {
	var params = req.params
	collectionDriver.findAll(req.params.collection, function(error, objs) {
		if(error) { res.send(400, error); }
		else {
			res.send(200, objs); 
		}
	});
});
 
// app.get('/:collection/:entity', function(req, res) { //I
//    var params = req.params;
//    var entity = params.entity;
//    var collection = params.collection;
//    if (entity) {
//        collectionDriver.get(collection, entity, function(error, objs) { //J
//           if (error) { res.send(400, error); }
//           else { res.send(200, objs); } //K
//        });
//    } else {
//       res.send(400, {error: 'bad url', url: req.url});
//    }
// });

app.get('/:collection/person/:entity', function(req, res) { //I
   var params = req.params;
   var entity = params.entity;
   console.log("THIS IS THE ENTITY " + entity);
   var collection = params.collection;
   if (entity) {
       collectionDriver.findItem(collection, entity, function(error, objs) { //J
          if (error) { res.send(400, error); }
          else { res.send(200, objs); } //K
       });
   } else {
      res.send(400, {error: 'bad url', url: req.url});
   }
});

//This creates a new route for the POST verb at line A which inserts 
//the body as an object into the specified collection by calling save() 
//that you just added to your driver. Line B returns the success code of 
//HTTP 201 when the resource is created.

app.post('/:collection', function(req, res) { //A
    var object = req.body;
    var collection = req.params.collection;
    collectionDriver.save(collection, object, function(err,docs) {
          if (err) { res.send(400, err); } 
          else { res.send(201, docs); } //B
     });
    //console.log(collection);
});
 
app.use(function (req,res) { //1
    res.render('404', {url:req.url}); //2
});

http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
