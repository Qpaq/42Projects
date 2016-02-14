//
//  ListTableViewController.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import UIKit
import MapKit


class ListTableViewController: UITableViewController, MKMapViewDelegate {
	
    let cities = ListPlaces().returnCities()
	
	var settingsMapType: MKMapType = MKMapType.Satellite
	
	
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

	
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cities.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("cellIdentifier", forIndexPath: indexPath) as! ListPlacesTableViewCell
        let city = cities[indexPath.row]
		
        cell.namePlaceLabel.text = city
		cell.cityPhoto.image = ListPlaces().returnPlaceInfo(city).photo
        return cell
    }

    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
		self.performSegueWithIdentifier("showNewLocation", sender: indexPath.row)
    }

	
	override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
		let dest = segue.destinationViewController as! MapViewController
		let i = sender as! Int
		
		dest.showLocation = cities.sort()[i]
		dest.currentMapType = settingsMapType
	}

	
	
	

	
    /*
    // Override to support conditional editing of the table view.
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }
    */

    /*
    // Override to support editing the table view.
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
        if editingStyle == .Delete {
            // Delete the row from the data source
            tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
        } else if editingStyle == .Insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }    
    }
    */

    /*
    // Override to support rearranging the table view.
    override func tableView(tableView: UITableView, moveRowAtIndexPath fromIndexPath: NSIndexPath, toIndexPath: NSIndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(tableView: UITableView, canMoveRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return false if you do not want the item to be re-orderable.
        return true
    }
    */

}
