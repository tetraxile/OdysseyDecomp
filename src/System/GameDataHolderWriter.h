#pragma once

class GameDataHolder;

class GameDataHolderWriter {
public:
    GameDataHolderWriter() {}

    GameDataHolderWriter(GameDataHolder* data) : mData(data) {}

    GameDataHolder* mData;
};
