//
//  EDC_Classical.swift
//  Simple
//
//  Created by Clement Chan on 9/17/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class EDC_Classical: UIViewController{
    
    override func viewDidLoad() {
        
        var leftSwipe = UISwipeGestureRecognizer(target: self, action: ("EDCClassicalSwipes:"))
        var rightSwipe = UISwipeGestureRecognizer(target: self, action: ("EDCClassicalSwipes:"))
        
        leftSwipe.direction = .Left
        rightSwipe.direction = .Right
        
        view.addGestureRecognizer(leftSwipe)
        view.addGestureRecognizer(rightSwipe)
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func EDCClassicalSwipes(sender:UISwipeGestureRecognizer){
        
        if(sender.direction == .Right){
            register_info.EDC_or_Classic = "Classic"
            println(register_info.EDC_or_Classic)
            loadDestinationVC()
            
        }
        else if(sender.direction == .Left){
            register_info.EDC_or_Classic = "EDC"
            println(register_info.EDC_or_Classic)
            loadDestinationVC()
        }
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Summary_Send", sender: nil)
    }
    
}
