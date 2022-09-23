package sample;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class CallEditDialogController {
    @FXML
    private TextField pNumber;
    @FXML
    private TextField name1;
    @FXML
    private TextField name2;
    @FXML
    private TextField date;
    @FXML
    private TextField time;
    @FXML
    private TextField duration;

    private Stage dialogStage;
    private Call call;
    private boolean okClicked = false;

    @FXML
    private void initialize(){}

    public void setDialogStage(Stage dialogStage){
        this.dialogStage = dialogStage;
    }
    public void setCall(Call call){
        this.call = call;
        pNumber.setText(Integer.toString(call.getpNumber()));
        name1.setText(call.getName1());
        name2.setText(call.getName2());
        date.setText(DateTransfer.formatDate(call.getDate()));
        time.setText(DateTransfer.formatTime(call.getTime()));
        duration.setText(Integer.toString(call.getCallDuration()));
    }
    public boolean isOkClicked(){
        return okClicked;
    }
    @FXML
    private void handleOk(){
        call.setpNumber(Integer.parseInt(pNumber.getText()));
        call.setName1(name1.getText());
        call.setName2(name2.getText());
        call.setDate(DateTransfer.parseDate(date.getText()));
        call.setTime(DateTransfer.parseTime(time.getText()));
        call.setCallDuration(Integer.parseInt(duration.getText()));

        okClicked = true;
        dialogStage.close();
    }
    @FXML
    private void handleCancel(){
        dialogStage.close();
    }
}
