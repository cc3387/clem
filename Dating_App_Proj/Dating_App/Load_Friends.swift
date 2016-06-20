//
//  Load_Friends.swift
//  Simple
//
//  Created by Clement Chan on 6/18/16.
//  Copyright © 2016 Clement Chan. All rights reserved.
//

import Foundation
import Firebase

class Load_Friends : UIViewController{
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationController?.setNavigationBarHidden(true, animated: false)
        let ref = Firebase(url:"https://simpleplus.firebaseio.com/users")
        ref.queryOrderedByChild("Email").queryEqualToValue(login.loginid)
            .observeEventType(.ChildAdded, withBlock: { snapshot in
                if let login_name = snapshot.value["Profile_Name"] as? String {
                    login_user.loginname = login_name;
                    print(login_user.loginname);
                    
                    if let ulat = snapshot.value["latitude"] as? Double{
                        login_user.latitude = ulat;
                        print(login_user.latitude);
                        if let ulon = snapshot.value["longitude"] as? Double{
                            login_user.longitude = ulon;
                            print(login_user.longitude);
                            if let username = snapshot.value["username"] as? String{
                                login_user.user_name = username;
                                print(login_user.user_name);
                                if let major = snapshot.value["Major"] as? String{
                                    login_user.major = major;
                                    print(login_user.major);
                                    if let university = snapshot.value["Education"] as? String{
                                        login_user.university = university;
                                        print(login_user.university);
                                        if let location = snapshot.value["location"] as? String{
                                            login_user.location = location;
                                            print(login_user.location);
                                            if let ProfileName = snapshot.value["Profile_Name"] as? String{
                                                login_user.Profile_Name = ProfileName;
                                                print(login_user.Profile_Name);
                            
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
        })
        
        //Download all the Friends' emails
        var friend = "https://simpleplus.firebaseio.com/friends/" + login_user.user_name + "_fd";
        let friendemail = Firebase(url:friend)
        frienduser.emailarray = [];
        friendemail.queryOrderedByChild("Email").observeEventType(.Value, withBlock:{friendsnapshot in
            for index in friendsnapshot.children.allObjects as! [FDataSnapshot]{
                if let id = index.value["Email"] as! String?{
                    frienduser.emailarray.append(id);
                }
            }
        })
        
        self.loadDestinationVC()
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("ToProfile", sender: nil)
    }
    
};

