//
//  PickerViewTest.swift
//  Dating_App
//
//  Created by Clement Chan on 7/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class Loc_PickerView: UIViewController,UIPickerViewDataSource, UIPickerViewDelegate {
    
    @IBOutlet weak var myPicker: UIPickerView!
    var Loc: String = "";

    override func viewDidLoad() {
        super.viewDidLoad()
        myPicker.delegate = self;
        myPicker.dataSource = self;
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func Nextq(sender: AnyObject) {
        updateLoc();
        loadDestinationVC();
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Google_Loc", sender: nil)
    }
    
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateLoc(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Loc = size;
        register_info.location = self.map(self.Loc);
        println(register_info.location);
    }
    
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }
    
    let pickerData = [
        ["Alabama AL", "Alaska AK", "Arizona AZ", "Arkansas AR", "California CA", "Colorado CO", "Conneticut CT", "Deleware DE", "Florida FL", "Georgia GA", "Hawaii HI", "Idaho ID", "Illinois IL", "Indiana IN", "Iowa IA", "Kansas", "Kentucky KY","Louisiana LA", "Maine ME", "Maryland  MD", "Massechusetts MA", "Michigan MI", "Minnesota MN", "Mississippi MS", "Missouri MO", "Montana MT", "Nebraska NE", "Nevada NV", "New Hampshire NH", "New Jersey NJ", "New Mexico NM", "New York NY", "North Carolina NC", "North Dakota ND", "Oklahoma OK", "Oregon OR", "Pennsylvania PA", "Rhode Island RI", "South Caroline SC", "South Dakota SD", "Tennessee TN", "Texas TX", "Utah UT", "Vermont VT", "Virginia VA", "Washington WA", "West Virginia WV", "Wisconsin WI", "Wyoming WY"]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        // pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 15)
        pickerLabel.font = UIFont(name: "System Thin", size: 20) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
    func map(loc:String) -> String {
        
        var location: String?;
        
        if (loc == "New York NY"){
        location = "NY";
        }
        
        else if (loc == "New Jersey NJ"){
        location = "NJ";
        }
        
        else if (loc == "Pennsylvania PA"){
        location = "PA";
        }
        
        else if (loc == "Florida FL"){
        location  = "FL";
        }
        
        else if (loc == "California CA"){
        location  = "CA";
        }
        
        else if (loc == "Illinois IL"){
        location  = "IL";
        }
        
        else if (loc == "Texas TX"){
        location  = "TX";
        }
        
        else if (loc == "Arizona AZ"){
        location = "AZ";
        }
        
        return location!;
    }
    
}



