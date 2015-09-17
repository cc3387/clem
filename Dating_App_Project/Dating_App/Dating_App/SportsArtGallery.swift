//
//  EDC_Classical.swift
//  Simple
//
//  Created by Clement Chan on 9/4/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class SportsArtGallery: UIViewController{
    
    override func viewDidLoad() {
        
        var leftSwipe = UISwipeGestureRecognizer(target: self, action: ("SportArtSwipes:"))
        var rightSwipe = UISwipeGestureRecognizer(target: self, action: ("SportArtSwipes:"))
        
        leftSwipe.direction = .Left
        rightSwipe.direction = .Right
        
        view.addGestureRecognizer(leftSwipe)
        view.addGestureRecognizer(rightSwipe)
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func SportArtSwipes(sender:UISwipeGestureRecognizer){
        
        if(sender.direction == .Right){
            register_info.sports_or_art = "Art_Gallery"
            loadDestinationVC()
            println(register_info.sports_or_art)
        }
        else if(sender.direction == .Left){
            register_info.sports_or_art = "Sports_Event"
            loadDestinationVC()
            println(register_info.sports_or_art)
        }
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("EDC_Classical", sender: nil)
    }
    
}
