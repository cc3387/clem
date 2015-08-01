//
//  ViewController.swift
//  WebServiceExample
//
//  Created by Regan Hsu on 7/29/15.
//  Copyright (c) 2015 Regan Hsu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var myNameLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        let manager = AFHTTPRequestOperationManager()
        self.myNameLabel.text = ""
        
        //create gray activity indicator view
        var activityIndicatorView = UIActivityIndicatorView(activityIndicatorStyle: .Gray)
        
        //add the activity to the viewcontroller's view
        view.addSubview(activityIndicatorView)
        
        //position the activity indicator view in the center
        activityIndicatorView.center = view.center
        
        activityIndicatorView.startAnimating()
        

        
        manager.GET( "http://api.randomuser.me/",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                
                println("Response: " + responseObject.description)
                if let results = responseObject["results"] as? NSArray {
                    if let user = results[0] as? NSDictionary {
                        if let user = user["user"] as? NSDictionary {
                            if let name = user["name"] as? NSDictionary {
                                if let first = name["first"] as? String {
                                    var fullName:String = first as String
                                    if let second = name["last"] as? String {
                                        fullName += " "
                                        fullName += second
                                        self.myNameLabel.text = fullName
                                        self.myNameLabel.adjustsFontSizeToFitWidth = true
                                    }
                                }
                            }
                        }
                        else {
                            println(user)
                            self.myNameLabel.text = "failed at cell"
                            self.myNameLabel.adjustsFontSizeToFitWidth = true
                        }
                    }
                    else {
                        self.myNameLabel.text = "failed at user"
                    }
                    //self.myNameLabel.text = nationality
                }
                else {
                    self.myNameLabel.text = "failed at results"
                }
                activityIndicatorView.stopAnimating()
 
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("uuuError: " + error.localizedDescription)
                //google timeout
                activityIndicatorView.stopAnimating()
                //self.myNameLabel.text = ":("
                
                var alert = UIAlertController(title: "Alert", message: "Message", preferredStyle: UIAlertControllerStyle.Alert)
                alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil))
                self.presentViewController(alert, animated: true, completion: nil)


                
                
        })
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

