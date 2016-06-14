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
        ["Alabama AL", "Alaska AK", "Arizona AZ", "Arkansas AR", "California CA", "Colorado CO", "Conneticut CT", "Deleware DE", "Florida FL", "Georgia GA", "Hawaii HI", "Idaho ID", "Illinois IL", "Indiana IN", "Iowa IA", "Kansas KS", "Kentucky KY","Louisiana LA", "Maine ME", "Maryland  MD", "Massechusetts MA", "Michigan MI", "Minnesota MN", "Mississippi MS", "Missouri MO", "Montana MT", "Nebraska NE", "Nevada NV", "New Hampshire NH", "New Jersey NJ", "New Mexico NM", "New York NY", "North Carolina NC", "North Dakota ND", "Oklahoma OK", "Oregon OR", "Pennsylvania PA", "Rhode Island RI", "South Caroline SC", "South Dakota SD", "Tennessee TN", "Texas TX", "Utah UT", "Vermont VT", "Virginia VA", "Washington WA", "West Virginia WV", "Wisconsin WI", "Wyoming WY", "International INT'l"]
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
        pickerLabel.font = UIFont(name: "System Thin", size: 12) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
    func map(loc:String) -> String {
        
        var location: String?;
        
        if(loc == "Alabama AL"){
        location = "AL";
        }
        else if(loc == "Alaska AK"){
        location = "AK";
        }
        else if(loc == "Arkansas AR"){
        location = "AR";
        }
        else if (loc == "Arizona AZ"){
        location = "AZ";
        }
        else if (loc == "California CA"){
        location  = "CA";
        }
        else if (loc == "Colorado CO"){
        location  = "CO";
        }
        else if (loc == "Conneticut CT"){
        location  = "CT";
        }
        else if (loc == "Deleware DE"){
        location  = "DE";
        }
        else if (loc == "Florida FL"){
        location  = "FL";
        }
        else if (loc == "Georgia GA"){
        location  = "GA";
        }
        else if (loc == "Hawaii HI"){
        location  = "HI";
        }
        else if(loc == "Idaho ID"){
        location = "ID";
        }
        else if(loc == "Illinois IL"){
        location = "IL";
        }
        else if(loc == "Indiana IN"){
        location = "IN";
        }
        else if(loc == "Iowa IA"){
        location = "IA";
        }
        else if(loc ==  "Kansas KS"){
        location = "KS";
        }
        else if(loc ==  "Kentucky KY"){
        location = "KY";
        }
        else if(loc ==  "Louisiana LA"){
        location = "LA";
        }
        else if(loc ==  "Maine ME"){
        location = "ME";
        }
        else if(loc ==  "Maryland  MD"){
        location = "MD";
        }
        else if(loc == "Massechusetts MA"){
        location = "MA";
        }
        else if(loc == "Michigan MI"){
        location = "MI";
        }
        else if(loc == "Minnesota MN"){
        location = "MN";
        }
        else if(loc == "Mississippi MS"){
        location = "MS";
        }
        else if(loc == "Missouri MO"){
        location = "MO";
        }
        else if(loc == "Montana MT"){
        location = "MT";
        }
        else if(loc == "Nebraska NE"){
        location = "NE";
        }
        else if(loc == "Nevada NV"){
        location = "NV";
        }
        else if(loc == "New Hampshire NH"){
        location = "NH";
        }
        else if(loc == "New Jersey NJ"){
        location = "NJ";
        }
        else if(loc == "New Mexico NM"){
        location = "NM";
        }
        else if(loc == "New York NY"){
        location = "NY";
        }
        else if(loc == "North Carolina NC"){
        location = "NC";
        }
        else if(loc == "North Dakota ND"){
        location = "ND";
        }
        else if(loc == "Oklahoma OK"){
        location = "OK";
        }
        else if(loc == "Oregon OR"){
        location = "OR";
        }
        else if(loc == "Pennsylvania PA"){
        location = "PA";
        }
        else if(loc == "Rhode Island RI"){
        location = "RI";
        }
        else if(loc == "South Caroline SC"){
        location = "SC";
        }
        else if(loc == "South Dakota SD"){
        location = "SD";
        }
        else if(loc == "Tennessee TN"){
        location = "TN";
        }
        else if(loc == "Texas TX"){
        location = "TX";
        }
        else if(loc == "Utah UT"){
        location = "UT";
        }
        else if(loc == "Vermont VT"){
        location = "VT";
        }
        else if(loc == "Virginia VA"){
        location = "VA";
        }
        else if(loc == "Washington WA"){
        location = "WA";
        }
        else if(loc == "West Virginia WV"){
        location = "WV";
        }
        else if(loc == "Wisconsin WI"){
        location = "WI";
        }
        else if(loc == "Wyoming WY"){
        location = "WY";
        }
        else if(loc == "International INT'l"){
        location = "INTL";
        }
        
        return location!;
    }
    
}



