package cc.openframeworks.ofxaddons.ofxandroidextendededittext;

import android.content.Context;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;
import cc.openframeworks.ofxaddons.ofxandroidextendededittext.ExtendedEditText;


public class OFXAndroidExtendedEditText extends cc.openframeworks.OFAndroidObject {
	private RelativeLayout rlayout;
	private ExtendedEditText eet;
	
	OFXAndroidExtendedEditText() {
        rlayout = (RelativeLayout) activity.findViewById(activity.getResources().getIdentifier("relativeLayout1", "id", activity.getPackageName()));
		eet = new ExtendedEditText(activity);
		eet.setOnEditorActionListener(new OnEditorActionListener() {
		    @Override
		    public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
		        boolean handled = false;
		        if (actionId == EditorInfo.IME_ACTION_DONE) {
			        String tn = eet.getText().toString();
					final InputMethodManager imm = (InputMethodManager) activity.getSystemService(Context.INPUT_METHOD_SERVICE);
					imm.hideSoftInputFromWindow(eet.getWindowToken(), 0);
		            remove();
		            setEditorText(tn);
		            handled = true;
		        }
		        return handled;
		    }
		});
	}
	
	
	public void add() {
		add("");
	}
	
	
	public void add(String hint) {
		final CharSequence h = (hint.length() == 0 ? "" : hint.subSequence(0, hint.length()));
		final ExtendedEditText et = eet;
		activity.runOnUiThread(new Runnable(){
			public void run() {
				et.setVisibility(EditText.VISIBLE);
				rlayout.addView(et);
				
				eet.setText(h);
				eet.requestFocus();
		        
				final InputMethodManager imm = (InputMethodManager) activity.getSystemService(Context.INPUT_METHOD_SERVICE);
				imm.showSoftInput(eet, InputMethodManager.SHOW_FORCED);
			}
		});
	}
	
	
	public void remove() {
		final ExtendedEditText et = eet;
		activity.runOnUiThread(new Runnable(){
			public void run() {
				// UI code goes here
				et.setVisibility(EditText.INVISIBLE);
				et.setClickable(false);
				rlayout.removeView(et);
			}
		});
	}
	
	
	public static native void setEditorText(String eetext);
	
	
	public boolean isShown() {
		return eet.isShown();
	}
		
	
	@Override
	protected void appPause() {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void appResume() {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void appStop() {
		// TODO Auto-generated method stub
		
	}

}
