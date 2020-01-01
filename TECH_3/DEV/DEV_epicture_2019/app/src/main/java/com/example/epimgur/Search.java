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
import android.widget.Button;
import android.widget.EditText;
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

public class Search extends AppCompatActivity {

    private OkHttpClient httpClient;

    private static class Photo {
        String id;
        String title;
    }

    private static class PhotoVH extends RecyclerView.ViewHolder {
        ImageView photo;
        TextView title;

        public PhotoVH(View itemView) {
            super(itemView);
        }
    }

    private void render(final List<Photo> photos) {
        RecyclerView rv = findViewById(R.id.rv_of_photos);
        rv.setLayoutManager(new LinearLayoutManager(this));
        RecyclerView.Adapter<PhotoVH> adapter = new RecyclerView.Adapter<PhotoVH>() {
            @NonNull
            @Override
            public PhotoVH onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
                PhotoVH vh = new PhotoVH(getLayoutInflater().inflate(R.layout.item, null));
                vh.photo = vh.itemView.findViewById(R.id.photo);
                vh.title = vh.itemView.findViewById(R.id.title);
                return vh;
            }

            @Override
            public void onBindViewHolder(@NonNull PhotoVH holder, int position) {
                Picasso.get().load("https://i.imgur.com/" + photos.get(position).id + ".jpg").into(holder.photo);
                holder.title.setText(photos.get(position).title);
            }

            @Override
            public int getItemCount() {
                return photos.size();
            }
        };
        rv.setAdapter(adapter);
        rv.addItemDecoration(new RecyclerView.ItemDecoration() {
            @Override
            public void getItemOffsets(Rect outRect, View view, RecyclerView parent, RecyclerView.State state) {
                outRect.bottom = 16;
            }
        });
    }

    private void fetchData(String search) {

        httpClient = new OkHttpClient.Builder().build();
        Request request = new Request.Builder()
                .url("https://api.imgur.com/3/gallery/search?q=" + search)
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
                    JSONObject data = new JSONObject(response.body().string());
                    JSONArray items = data.getJSONArray("data");
                    final List<Photo> photos = new ArrayList<Photo>();
                    for (int i = 0; i < items.length(); i++) {
                        JSONObject item = items.getJSONObject(i);
                        final Photo photo = new Photo();
                        if (item.getBoolean("is_album")) {
                            photo.id = item.getString("cover");
                        } else {
                            photo.id = item.getString("id");
                        }
                        photo.title = item.getString("title");
                        photos.add(photo);
                    }
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            render(photos);
                        }
                    });
                } catch (JSONException e) {

                }
            }
        });

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);
        final EditText searchEditText = findViewById(R.id.searchEditText);
        Button searchbtn = findViewById(R.id.searchbtn);
        searchbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                fetchData(searchEditText.getText().toString());
                Log.e("LOG", searchEditText.getText().toString());
            }
        });

    }
}
