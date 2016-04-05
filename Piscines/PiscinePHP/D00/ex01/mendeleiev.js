function addToResult(element) {
	var result = "";
	result += "<td class='withborder'>";
	result += "<span class='symbol'>"+ element.small +"</span>";
	result += "<span class='number'>"+ element.number +"</span>";
	result += "<span class='weight'>"+ element.molar +"</span>";
	result += '</td>';
	return (result);
}

function printTable(table) {
	var result = "";

	table.table.forEach(function(line) {
		result += '<tr>';
		line.elements.forEach(function(element) {
			result += addToResult(element);
		});
		result += '</tr>';
	});
	result += '<tr>';
	table.lanthanoids.forEach(function(element) {
		result += addToResult(element);
	});
	result += '</tr>';

	result += '<tr>';
	table.actinoids.forEach(function(element) {
		result += addToResult(element);
	});
	result += '</tr>';


	console.log(result);
};
var xhr = new XMLHttpRequest();
xhr.onreadystatechange = function() {
	if (xhr.readyState === XMLHttpRequest.DONE) {
		if (xhr.status === 200) {
			printTable(JSON.parse(xhr.responseText));
		} else {
			console.log("error");
		}
	}
};
xhr.open("GET", "https://raw.githubusercontent.com/diniska/chemistry/master/PeriodicalTable/periodicTable.json", true);
xhr.send();
