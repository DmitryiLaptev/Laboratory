package sample;

import javafx.beans.property.ObjectProperty;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;

import java.time.LocalDate;

public class CallOverviewController {
    @FXML
    private TableView<Call> callTable;
    @FXML
    private TableColumn<Call, Integer> pNumber;
    @FXML
    private TableColumn<Call, String> name1;
    @FXML
    private TableColumn<Call, String> name2;
    @FXML
    private TableColumn<Call, String> date;
    @FXML
    private TableColumn<Call, String> time;
    @FXML
    private TableColumn<Call, Integer> callDuration;


    private Main mainApp;
    public CallOverviewController(){}

    @FXML
    private void initialize(){
        pNumber.setCellValueFactory(Call -> Call.getValue().pNumberProperty().asObject());
        name1.setCellValueFactory(Call -> Call.getValue().name1Property());
        name2.setCellValueFactory(Call -> Call.getValue().name2Property());
        callDuration.setCellValueFactory(Call -> Call.getValue().callDurationProperty().asObject());
        date.setCellValueFactory(Call -> Call.getValue().dateProperty().asString());
        time.setCellValueFactory(Call -> Call.getValue().timeProperty().asString());
    }
    @FXML
    private void deleteButton(){
        int selectedIndex = callTable.getSelectionModel().getSelectedIndex();
        callTable.getItems().remove(selectedIndex);
    }
    @FXML
    private void handleNewCall(){
        Call tCall = new Call(1,"введите имя1","введите имя2",1, 2000,1,1,1,1);
        boolean okClicked = mainApp.showCallEditDialog(tCall);
        if(okClicked){
            mainApp.getCallList().add(tCall);
        }
    }
    @FXML
    private void handleEditCall() {
        Call sCall = callTable.getSelectionModel().getSelectedItem();
        boolean okClicked = mainApp.showCallEditDialog(sCall);
        if (okClicked) {
            int selectedIndex = callTable.getSelectionModel().getSelectedIndex();
            callTable.getItems().remove(selectedIndex);
            callTable.getItems().add(sCall);
        }
    }

    public void setMainApp(Main mainApp){
        this.mainApp = mainApp;
        callTable.setItems(mainApp.getCallList());
    }
}
