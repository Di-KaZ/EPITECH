package com.example.epimgur;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.graphics.Rect;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class Account extends AppCompatActivity {
    private OkHttpClient httpClient;

    private void fetchData() {

        httpClient = new OkHttpClient.Builder().build();
        Request request = new Request.Builder()
                .url("https://api.imgur.com/3/account/MOUSSED")
                .header("Authorization","Bearer 2eaea71ee960f9c5db536410b332e938971c39fa")
                .header("User-Agent","Epimgur")
                .build();
        httpClient.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                Log.e("TAG", "Error " + e);
            }

            @Override
            public void onResponse(Call call, Response response) throws IOException {
                try {
                    ImageView profileImageView = findViewById(R.id.profileImageView);
                    TextView nameTextView = findViewById(R.id.nametextView);
                    JSONObject data = new JSONObject(response.body().string());
                    JSONArray items = data.getJSONArray("data");
                    nameTextView.setText("yeyeye");
                    Picasso.get().load(items.getJSONObject(0).getString("avatar") + ".jpg").into(profileImageView);
                } catch (JSONException e) {

                }
            }
        });

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_account);
        fetchData();
    }
}
